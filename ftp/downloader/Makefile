# ex:ts=8
# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	2.5.7.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://d4x.krasu.ru/files/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/
DISTNAME=	d4x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for downloading via FTP or HTTP with GUI

BUILD_DEPENDS=	${LOCALBASE}/include/boost/smart_ptr.hpp:${PORTSDIR}/devel/boost \
		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_GNOME=	esound gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_GENGETOPT=no

MAN1=		nt.1

DATADIR=	${PREFIX}/share/d4x
DOCSDIR=	${PREFIX}/share/doc/d4x

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=	yes
CONFIGURE_ENV+=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="${OPENSSLLIB}"
LDFLAGS+=	-lssl -lcrypto
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/sh|${LOCALBASE}/bin/bash|g ; \
		 s| == "xno"| = "xno"|g ; \
		 s| $$OPTFLAGS||g ; \
		 s| $$OS_CXXFLAGS||g ; \
		 s|-lpthread||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| DOC||g ; \
		 s| share||g' ${WRKSRC}/Makefile.in
.if ${OSVERSION} < 500000
.for f in main/addr.cc main/dlist.cc main/ftpd.cc main/face/mywidget.cc
	@${REINPLACE_CMD} -e 's|pass\.clear()|pass = ""|g ; \
		 s|user\.clear()|user = ""|g ; \
		 s|host\.clear()|host = ""|g ; \
		 s|file\.clear()|file = ""|g ; \
		 s|params\.clear()|params = ""|g ; \
		 s|tag\.clear()|tag = ""|g ; \
		 s|path\.clear()|path = ""|g' ${WRKSRC}/${f}
.endfor
.for f in main/filter.h
	@${REINPLACE_CMD} -e 's|<istream>|<iostream>|g ; \
		 s|<ostream>|<iostream>|g' ${WRKSRC}/${f}
.endfor
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/DOC/nt.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC}/share --exclude "Makefile*" \
		-cf - . | ${TAR} -C ${DATADIR} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/DOC --exclude "Makefile*" --exclude "nt.1" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
