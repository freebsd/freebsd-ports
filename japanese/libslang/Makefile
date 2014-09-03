# Created by: IWASHITA Yoji <shuna@pop16.odn.ne.jp>
# $FreeBSD$

PORTNAME=	libslang
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	1
CATEGORIES=	japanese devel
MASTER_SITES=	http://www.emaillab.org/mutt/tools/ \
		http://my.reset.jp/~iwashita/mutt/distfiles/
DISTNAME=	slang-${VERSION}jp${JP_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library permits a programmer to develop software

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/slang
ALL_TARGET=	all elf
INSTALL_TARGET=	install-elf
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	libslang2-[0-9]* libslang-1.*[^j]*

DOCSDIR=	${PREFIX}/share/doc/slang

OPTIONS_DEFINE=	DOCS

VERSION=	1.4.5
JP_VERSION=	2

post-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} slang-j.doc \
		${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libslang.so.[0-9]*

.include <bsd.port.mk>
