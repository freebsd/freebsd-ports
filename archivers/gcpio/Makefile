# $FreeBSD$

PORTNAME=	cpio
PORTVERSION=	2.13
CATEGORIES=	archivers
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU cpio copies files to and from archives

LICENSE=	GPLv3

TEST_DEPENDS=	autom4te:devel/autoconf

USES=		cpe tar:bzip2

CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--with-rmt=/etc/rmt
TEST_TARGET=	check

INFO=		cpio

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
