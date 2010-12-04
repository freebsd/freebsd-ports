# New ports collection makefile for:	rudiments
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudiments
PORTVERSION=	0.32
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility C++ class library for daemons, clients, servers and more

USE_GNOME=	gnometarget pkgconfig
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
		PTHREADLIB="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-ssl-includes=-I${OPENSSLINC} \
		--with-ssl-libs=-L${OPENSSLLIB} \
		--disable-pcre
USE_LDCONFIG=	yes

ROOTDIRS=	classes css programming programming/parts

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/perl,${PREFIX}/bin/perl,g' \
		${WRKSRC}/doc/programming/insert.pl
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for dirs in ${ROOTDIRS}
	@${MKDIR} ${DOCSDIR}/${dirs}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/classes/*.html \
		${DOCSDIR}/classes
	@${INSTALL_DATA} ${WRKSRC}/doc/css/*.css \
		${DOCSDIR}/css
	@${INSTALL_DATA} ${WRKSRC}/doc/programming/*.html \
		${DOCSDIR}/programming
	@${INSTALL_SCRIPT} ${WRKSRC}/doc/programming/*.pl \
		${DOCSDIR}/programming
	@${INSTALL_DATA} ${WRKSRC}/doc/programming/parts/*.html \
		${DOCSDIR}/programming/parts
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html \
		${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.gif \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
