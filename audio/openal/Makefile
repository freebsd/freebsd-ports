# New ports collection makefile for:	openal
# Date created:		25 September 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	20020217
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.openal.org/pub/openal/

MAINTAINER=	erik@smluc.org

WRKSRC=		${WRKDIR}/tmp/${PORTNAME}/linux

USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's|autoconf|${AUTOCONF}|; \
		s|autoheader|${AUTOHEADER}|' ${WRKSRC}/autogen.sh

pre-configure:
	@cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info
	@install-info ${PREFIX}/info/openal.info ${PREFIX}/info/dir

.include <bsd.port.mk>
