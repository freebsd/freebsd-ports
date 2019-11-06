# Created by: Chia-liang Kao <clkao@clkao.org>
# $FreeBSD$

PORTNAME=	Cdk
PORTVERSION=	5.20150928
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://invisible-island.net/cdk/
PKGNAMEPREFIX=	p5-
DISTNAME=	cdk-perl-${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for Curses Development Kit

BROKEN=		unfetchable

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdk.so:devel/cdk

USES=		localbase ncurses perl5 tar:tgz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

CPPFLAGS+=	-I${NCURSESINC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cdk/Cdk.so

.include <bsd.port.mk>
