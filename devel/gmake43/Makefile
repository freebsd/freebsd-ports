PORTNAME=	gmake
PORTVERSION=	4.3 # pre-slowdown caused by the issues described here: https://savannah.gnu.org/bugs/?65533
CATEGORIES=	devel
MASTER_SITES=	GNU/make
DISTNAME=	make-${PORTVERSION}
PKGNAMESUFFIX=	43

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GNU version of 'make' utility
WWW=		https://www.gnu.org/software/make/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=g \
		--without-guile

USES=		cpe tar:lz
CPE_VENDOR=	gnu
CPE_PRODUCT=	make

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

INFO=		make

.include <bsd.port.mk>
