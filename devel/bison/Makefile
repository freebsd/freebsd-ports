# Ports collection makefile for:  bison
# Date created:			  27 Mar 1999
# Whom:				  Jerry Hicks
#
# $FreeBSD$
#

PORTNAME=	bison
PORTVERSION=	1.75
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parser generator from FSF, (mostly) compatible with Yacc

CONFLICTS=	bison-[0-9]+

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
.if !defined(WITHOUT_NLS)
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old
PLIST_SUB=	NLS=""
.else
PLIST_SUB=	NLS="@comment "
.endif
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS=	--disable-nls
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"

MAN1=		bison.1

.ifdef USE_BISON
.error You have `USE_BISON' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/bison.info*

.include <bsd.port.mk>
