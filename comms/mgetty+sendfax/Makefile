PORTNAME=	mgetty
PORTVERSION=	1.1.37
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://mgetty.greenie.net/pub/mgetty/source/1.1/
DISTNAME=	${PORTNAME}${PORTVERSION}-Jun05

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Handle external logins, send and receive faxes

LICENSE=	GPLv2

BROKEN_aarch64=		fails to compile: error: initializer element is not a compile-time constant
BROKEN_mips64=		fails to compile: error: initializer element is not a compile-time constant
BROKEN_riscv64=		fails to compile: error: initializer element is not a compile-time constant

USES=		cpe makeinfo perl5 shebangfix
USE_CSTD=	gnu89
SHEBANG_FILES=	samples/fax samples/new_fax.all/new_fax samples/new_fax.mime1 \
		samples/new_fax.th samples/coverpg-pl.ps samples/faxview.th

CPE_VENDOR=	mgetty_project
SUB_FILES=	pkg-message mgettycfg
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS=	INFODIR=${PREFIX}/${INFO_PATH}
MAKE_FLAGS=	CFLAGS="${CFLAGS}" prefix=${PREFIX} LOCALBASE=${LOCALBASE}\
		STAGEDIR=${STAGEDIR} -f
ALL_TARGET=	noident all
INFO=		mgetty
CFLAGS+=	-DAUTO_PPP

CONFLICTS_INSTALL=	hylafax

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	FIDO
FIDO_DESC=	Enable FIDO EMSI support
FIDO_CFLAGS=	-DFIDO

pre-install:
	@(cd ${WRKSRC}/doc; ${MAKE} manpages)

post-install:
.for a in dialin.config faxheader faxrunq.config login.config
	cd ${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/ && ${MV} ${a} ${a}.sample
.endfor
	${INSTALL_DATA} -m 600 ${WRKSRC}/voice/voice.conf-dist \
		${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/voice.conf.sample
	cd ${WRKSRC} && ${COPYTREE_BIN} samples\
		${STAGEDIR}${PREFIX}/lib/mgetty+sendfax
	${INSTALL_SCRIPT} ${WRKDIR}/mgettycfg ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
