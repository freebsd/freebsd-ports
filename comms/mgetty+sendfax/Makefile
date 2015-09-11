# Created by: rkw
# $FreeBSD$

PORTNAME=	mgetty
PORTVERSION=	1.1.35
PORTREVISION=	8
CATEGORIES=	comms
MASTER_SITES=	ftp://mgetty.greenie.net/pub/mgetty/source/1.1/
DISTNAME=	${PORTNAME}${PORTVERSION}-Feb22

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Handle external logins, send and receive faxes

LICENSE=	GPLv2

USE_CSTD=	gnu89
USES=		makeinfo perl5 shebangfix
SHEBANG_FILES=	samples/fax \
		samples/new_fax.all/new_fax \
		samples/new_fax.mime1

SUB_FILES=	pkg-message mgettycfg
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_FLAGS=	CFLAGS="${CFLAGS}" prefix=${PREFIX} LOCALBASE=${LOCALBASE} STAGEDIR=${STAGEDIR} -f
ALL_TARGET=	noident all
INFO=		mgetty

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	FIDO

FIDO_DESC=	Enable FIDO EMSI support

CFLAGS+=	-DAUTO_PPP

FIDO_CFLAGS=	-DFIDO

pre-install:
	@(cd ${WRKSRC}/doc; ${MAKE} manpages)

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/dialin.config \
		${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/dialin.config.sample
	@${MV} ${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/faxheader \
		${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/faxheader.sample
	@${MV} ${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/faxrunq.config \
		${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/faxrunq.config.sample
	@${MV} ${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/login.config \
		${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/login.config.sample
	${INSTALL_DATA} -m 600 ${WRKSRC}/voice/voice.conf-dist \
		${STAGEDIR}${PREFIX}/etc/mgetty+sendfax/voice.conf.sample
	${TAR}  -cf - -C ${WRKSRC} samples | ${TAR}  -xf - -C ${STAGEDIR}${PREFIX}/lib/mgetty+sendfax/
	${INSTALL_SCRIPT} ${WRKDIR}/mgettycfg ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mgetty+sendfax/faxq-helper

.include <bsd.port.mk>
