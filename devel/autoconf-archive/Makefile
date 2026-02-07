PORTNAME=	autoconf-archive
DISTVERSION=	2024.10.16
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of useful GNU Autoconf macros
WWW=		https://savannah.gnu.org/projects/autoconf-archive

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo tar:xz

GNU_CONFIGURE=	yes
NO_ARCH=	yes

INFO=		autoconf-archive
PLIST_SUB=	MACRODIR=share/aclocal

.include <bsd.port.mk>
