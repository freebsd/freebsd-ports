PORTNAME=	d2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Modern text-to-diagram language
WWW=		https://www.d2lang.com

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	git:devel/git@tiny

USES=		go:1.27+,modules
GO_MODULE=	github.com/d2lang/d2

PLIST_FILES=	bin/d2

.include <bsd.port.mk>
