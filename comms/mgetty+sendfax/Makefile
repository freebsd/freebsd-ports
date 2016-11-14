# Created by: rkw
# $FreeBSD$

PORTNAME=	mgetty
PORTVERSION=	1.1.37
CATEGORIES=	comms
MASTER_SITES=	ftp://mgetty.greenie.net/pub/mgetty/source/1.1/
DISTNAME=	${PORTNAME}${PORTVERSION}-Jun05

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Handle external logins, send and receive faxes

LICENSE=	GPLv2

USE_CSTD=	gnu89
USES=		makeinfo perl5 shebangfix
SHEBANG_FILES=	samples/fax samples/new_fax.all/new_fax samples/new_fax.mime1

SUB_FILES=	pkg-message mgettycfg
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_FLAGS=	CFLAGS="${CFLAGS}" prefix=${PREFIX} LOCALBASE=${LOCALBASE}\
		STAGEDIR=${STAGEDIR} -f
ALL_TARGET=	noident all
INFO=		mgetty
CFLAGS+=	-DAUTO_PPP

MAKE_JOBS_UNSAFE=	yes

BROKEN_aarch64=		Fails to compile: error: initializer element is not a compile-time constant
BROKEN_mips64=		Fails to compile: error: initializer element is not a compile-time constant

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
