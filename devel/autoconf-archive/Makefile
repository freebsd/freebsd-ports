PORTNAME=	autoconf-archive
PORTVERSION=	2026.11.11
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of useful GNU Autoconf macros
WWW=		https://www.gnu.org/software/autoconf-archive/ \
		https://savannah.gnu.org/projects/autoconf-archive \
		https://github.com/autoconf-archive/autoconf-archive

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo tar:xz

GNU_CONFIGURE=	yes
NO_ARCH=	yes

INFO=		autoconf-archive
PLIST_SUB=	MACRODIR=share/aclocal

.include <bsd.port.mk>
