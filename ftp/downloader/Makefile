# ex:ts=8
# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	2.5.0
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/files/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/
DISTNAME=	d4x-${PORTVERSION}final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for downloading via ftp or http with GUI

USE_GNOME=	esound gtk20
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-release

MAN1=		nt.1

DATADIR=	${PREFIX}/share/d4x
DOCSDIR=	${PREFIX}/share/doc/d4x

post-patch:
	@${REINPLACE_CMD} -e 's| $$OPTFLAGS||g ; \
		 s| $$OS_CXXFLAGS||g ; \
		 s|-lpthread||g ; \
		 s|#define GTK_DISABLE_DEPRECATED||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| DOC||g ; \
		 s| share||g' ${WRKSRC}/Makefile.in

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

.include <bsd.port.mk>
