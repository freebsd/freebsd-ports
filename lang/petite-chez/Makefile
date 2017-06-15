# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	petite-chez
PORTVERSION=	8.4
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.scheme.com/download/ \
		http://tx97.net/pub/distfiles/
DISTNAME=	pcsv${PORTVERSION}-${CHEZ_MACHTYPE}

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Free interpreter for Chez Scheme system

# Both install bin/scheme-script
CONFLICTS=	ikarus-*

ONLY_FOR_ARCHS=	i386 amd64

NO_PACKAGE=	User must accept license terms before installation

.if defined(PACKAGE_BUILDING)
IGNORE=		user must accept license terms before installation
.endif

OPTIONS_DEFINE=	THREADS

WRKSRC=		${WRKDIR}/csv${PORTVERSION}/custom
HAS_CONFIGURE=	yes
USES=		iconv
CONFIGURE_ARGS=	--installprefix=${PREFIX} \
		--installman=${MANPREFIX}/man \
		--temproot=${STAGEDIR} \
		--force-relink \
		--nogzip-man-pages \
		-m=${CHEZ_MACHTYPE}
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	build

PLIST_SUB=	CHEZ_VERSION="${PORTVERSION}" \
		CHEZ_MACHTYPE="${CHEZ_MACHTYPE}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CHEZ_MACHTYPE=	i3fb
.elif ${ARCH} == "amd64"
CHEZ_MACHTYPE=	a6fb
.endif

.if ${PORT_OPTIONS:MTHREADS}
CHEZ_MACHTYPE:=	t${CHEZ_MACHTYPE}
.endif

post-extract:
.if !defined(PETITECHEZ_AGREE_LICENSE) || ${PETITECHEZ_AGREE_LICENSE} != "yes"
	@${ECHO}
	@${ECHO} "AGREEMENT: ${WRKDIR}/csv${PORTVERSION}/petite.lic"
	@${ECHO}
	@${ECHO} "BEFORE PROCEEDING WITH THE INSTALLATION, YOU MUST FIRST READ"
	@${ECHO} "THE ENTIRE AGREEMENT.  BY PROCEEDING WITH THE INSTALLATION,"
	@${ECHO} "YOU EXPRESSLY AGREE TO BE BOUND BY THE TERMS AND CONDITIONS"
	@${ECHO} "OF THE AGREEMENT.  IF YOU DO NOT AGREE TO ALL OF THE TERMS"
	@${ECHO} "AND CONDITIONS OF THIS AGREEMENT, DO NOT PROCEED WITH"
	@${ECHO} "THE INSTALLATION."
	@${ECHO}
	@${ECHO} "Build with PETITECHEZ_AGREE_LICENSE=yes to continue."
	@${FALSE}
.endif

post-configure:
	@${REINPLACE_CMD} \
		-e 's|C=gcc|C=${CC}|' \
		-e 's|-L/usr/local/lib|-L/usr/lib -L${LOCALBASE}/lib|' \
		${WRKSRC}/Mf-${CHEZ_MACHTYPE}

post-install:
.for bin in petite scheme-script
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/${bin}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${bin}
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor

.include <bsd.port.post.mk>
