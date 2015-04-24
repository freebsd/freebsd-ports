# Created by: Chia-liang Kao <clkao@clkao.org>
# $FreeBSD$

PORTNAME=	Cdk
PORTVERSION=	5.20120324
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://dickey.his.com/cdk/
PKGNAMEPREFIX=	p5-
DISTNAME=	cdk-perl-${PORTVERSION:C,^[0-9]\.,,}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for Curses Development Kit

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libcdk.so:${PORTSDIR}/devel/cdk

USES=		perl5 tar:tgz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DEPRECATED=	Does not work with 5.18 or above
EXPIRATION_DATE=2015-07-31

.include <bsd.port.pre.mk>

.if ${PERL_VER} >= 5.18
BROKEN=		Does not build with Perl 5.18 or above
.endif

.include <bsd.port.post.mk>
