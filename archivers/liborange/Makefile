# New ports collection makefile for:	orange
# Date Created:				January 2005
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	liborange
PORTVERSION=	0.4
CATEGORIES=	archivers
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Library to extract CAB files from self-extracting installers

RUN_DEPENDS=	cabextract:${PORTSDIR}/archivers/cabextract \
		unzip:${PORTSDIR}/archivers/unzip

OPTIONS=	LIBSYNCE	"Build with libsynce support"			on \
		LIBDYNAMITE	"Build with libdynamite support"		on \
		LIBUNSHIELD	"Build with libunshield support"		on \
		INNO		"Build with expermential Inno Setup support"	off \
		VISE		"Build with expermential VISE support"		off \
		MSI		"Build with expermential MSI support"		off

MAKE_JOBS_SAFE=	yes

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_ICONV=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		orange.1

.include <bsd.port.pre.mk>

.if !defined(WITH_LIBSYNCE)
CONFIGURE_ARGS+=	--without-libsynce
REQUIRES+=	libsynce
.else
LIB_DEPENDS+=		synce.0:${PORTSDIR}/palm/synce-libsynce
CONFIGURE_ARGS+=	--with-libsynce
.endif

.if !defined(WITH_LIBDYNAMITE)
CONFIGURE_ARGS+=	--without-libdynamite
REQUIRES+=	libdynamite
.else
LIB_DEPENDS+=		dynamite.0:${PORTSDIR}/archivers/libdynamite
CONFIGURE_ARGS+=	--with-libdynamite
.endif

.if !defined(WITH_LIBUNSHIELD)
CONFIGURE_ARGS+=	--without-libunshield
REQUIRES+=	libunshield
.else
LIB_DEPENDS+=		unshield.0:${PORTSDIR}/archivers/unshield
CONFIGURE_ARGS+=	--with-libunshield
.endif

.if defined(WITH_INNO)
CONFIGURE_ARGS+=	--enable-inno
.endif

.if defined(WITH_VISE)
CONFIGURE_ARGS+=	--enable-vise
.endif

.if defined(WITH_MSI)
CONFIGURE_ARGS+=	--enable-msi --with-libgsf
LIB_DEPENDS+=		gsf-1.114:${PORTSDIR}/devel/libgsf
.endif

post-patch:
.for req in ${REQUIRES}
	@${REINPLACE_CMD} -e 's|${req}||' ${WRKSRC}/${PORTNAME}.pc.in
.endfor

.include <bsd.port.post.mk>
