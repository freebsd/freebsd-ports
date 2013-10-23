# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sysbench
PORTVERSION=	0.4.12
PORTREVISION=	1
CATEGORIES=	benchmarks databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular, cross-platform, and multi-threaded benchmark tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool

OPTIONS_DEFINE=	LARGEFILE MYSQL PGSQL DOCS
OTPIONS_DEFAULT=	LARGEFILE MYSQL
LARGEFILE_DESC=	Enable Largefile support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLARGEFILE}
CONFIGURE_ARGS+=	--enable-largefile
.else
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if ${PORT_OPTIONS:MPOSTGRESQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql
.else
CONFIGURE_ARGS+=	--with-pgsql=no
.endif

post-configure:
	@${REINPLACE_CMD} -e 's/^program_transform_name/#/' \
		${WRKSRC}/Makefile ${WRKSRC}/sysbench/Makefile

.if empty(PORT_OPTIONS:MDOCS)
post-install:
	${RM} ${DOCSDIR}/manual.html
	${RMDIR} ${DOCSDIR}
.endif

.include <bsd.port.mk>
