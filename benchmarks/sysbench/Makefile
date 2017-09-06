# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sysbench
PORTVERSION=	1.0.9
CATEGORIES=	benchmarks databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Scriptable database and system performance benchmark

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xxd:editors/vim
LIB_DEPENDS=	libck.so:devel/concurrencykit \
		libluajit-5.1.so:lang/luajit

OPTIONS_DEFINE=	LFS MYSQL PGSQL
OPTIONS_DEFAULT=LFS MYSQL

CONFIGURE_ARGS=	--with-system-ck --with-system-luajit
GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pkgconfig

GH_ACCOUNT=	akopytov
USE_GITHUB=	yes

LFS_CONFIGURE_ENABLE=	largefile
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USES=		mysql
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USES=		pgsql

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| doc||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|__linux__|__FreeBSD__|' ${WRKSRC}/src/sb_util.h

.include <bsd.port.mk>
