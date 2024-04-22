PORTNAME=	hexer
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://devel.ringlet.net/files/editors/hexer/ \
		LOCAL/ehaupt

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Multi buffer editor for binary files
WWW=		https://gitlab.com/hexer/hexer

LICENSE=	DEMETRIO
LICENSE_NAME=	Sascha Demetrio Custom License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man1
ALL_TARGET=	all

OPTIONS_DEFINE=	MYC
OPTIONS_DEFAULT=MYC
OPTIONS_SUB=	yes

MYC_DESC=	Builtin calculator

MYC_ALL_TARGET=	myc

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=14
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexer

post-install-MYC-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/myc

.include <bsd.port.mk>
