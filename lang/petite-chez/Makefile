# New ports collection makefile for:	petite-chez
# Date created:		27 Mar 2009
# Whom:			Vitaly Magerya <vmagerya@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	petite-chez
PORTVERSION=	7.4
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.scheme.com/download/
DISTNAME=	pcsv${PORTVERSION}-${CHEZ_MACHTYPE}

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Free interpreter for Chez Scheme system

ONLY_FOR_ARCHS=	i386

NO_PACKAGE=	user must accept license terms before installation

.if defined(PACKAGE_BUILDING)
IGNORE=		user must accept license terms before installation
.endif

OPTIONS=	THREADS "Install threaded version" off

WRKSRC=		${WRKDIR}/csv${PORTVERSION}/custom
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--installprefix=${PREFIX} \
		--installman=${MANPREFIX}/man \
		--force-relink \
		-m=${CHEZ_MACHTYPE}

ALL_TARGET=	build

MAN1=		petite.1

PLIST_SUB=	CHEZ_VERSION="${PORTVERSION}" \
		CHEZ_MACHTYPE="${CHEZ_MACHTYPE}"

.include <bsd.port.pre.mk>

.if defined(WITH_THREADS)
CHEZ_MACHTYPE=	ti3fb
.else
CHEZ_MACHTYPE=	i3fb
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
	@${REINPLACE_CMD} -e 's|group=root|group=wheel|' \
		${WRKSRC}/Mf-${CHEZ_MACHTYPE}
	@${REINPLACE_CMD} -e 's|C=gcc|C=${CC}|' \
		${WRKSRC}/Mf-${CHEZ_MACHTYPE}

.include <bsd.port.post.mk>
