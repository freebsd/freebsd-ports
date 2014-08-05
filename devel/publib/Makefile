# Created by: never@nevermind.kiev.ua
# $FreeBSD$

PORTNAME=	publib
PORTVERSION=	0.39
CATEGORIES=	devel
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/p/publib/
DISTNAME=	publib_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Publib is a library of C functions for various purposes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/framework/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/objs
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../framework/configure

USES=		gmake
GNU_CONFIGURE=	yes

pre-configure::
	${MKDIR} ${WRKSRC}/objs
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/Default.config > ${WRKSRC}/objs/Default.config

.include <bsd.port.mk>
