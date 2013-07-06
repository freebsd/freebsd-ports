# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	m17n-db
PORTVERSION=	1.6.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}:m17n \
		${MASTER_SITE_GNU:S/$/:glibc/}
MASTER_SITE_SUBDIR=	m17n/:m17n \
		glibc/:glibc
DISTFILES=	${M17N_DISTFILE}:m17n \
		${GLIBC_DISTFILE}:glibc
EXTRACT_ONLY=	${M17N_DISTFILE}

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Data files for the m17n library

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-charmaps=${CHARMAPSDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

M17N_DISTFILE=	${DISTNAME}${EXTRACT_SUFX}
GLIBC_VERSION=	2.3.6
GLIBC_DISTFILE=	glibc-${GLIBC_VERSION}.tar.bz2
CHARMAPSDIR=	glibc-${GLIBC_VERSION}/localedata/charmaps

post-extract:
	cd ${WRKSRC}; ${TAR} xjf ${DISTDIR}/${GLIBC_DISTFILE} ${CHARMAPSDIR}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${datadir}/pkgconfig|$${prefix}/libdata/pkgconfig|g'

.include <bsd.port.mk>
