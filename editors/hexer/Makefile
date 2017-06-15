# $FreeBSD$

PORTNAME=	hexer
PORTVERSION=	1.0.3
CATEGORIES=	editors
MASTER_SITES=	http://devel.ringlet.net/files/editors/hexer/ \
		LOCAL/ehaupt

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Multi buffer editor for binary files

LICENSE=	DEMETRIO
LICENSE_NAME=	Sascha Demetrio Custom License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

OPTIONS_DEFINE=	MYC
MYC_DESC=	Builtin calculator
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=MYC

ALL_TARGET=	all
MYC_ALL_TARGET=	myc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexer

post-install-MYC-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/myc

.include <bsd.port.mk>
