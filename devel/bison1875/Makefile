# Ports collection makefile for:  bison
# Date created:			  27 Mar 1999
# Whom:				  Jerry Hicks
#
# $FreeBSD$
#

PORTNAME=	bison
PORTVERSION=	1.875
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	A parser generator from FSF, (mostly) compatible with Yacc

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

CONFLICTS=	bison-1.7[0-9]*

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"

MAN1=		bison.1
INFO=		bison

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.ifdef USE_BISON
.error You have `USE_BISON' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/bison.info*

post-install:
	${LN} -sf ${PREFIX}/bin/bison ${PREFIX}/bin/bison1875

.include <bsd.port.mk>
