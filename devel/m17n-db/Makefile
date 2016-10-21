# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	m17n-db
PORTVERSION=	1.7.0
CATEGORIES=	devel textproc
MASTER_SITES=	SAVANNAH/m17n:m17n \
		GNU/glibc:glibc
DISTFILES=	${M17N_DISTFILE}:m17n \
		${GLIBC_DISTFILE}:glibc
EXTRACT_ONLY=	${M17N_DISTFILE}

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Data files for the m17n library

OPTIONS_DEFINE=	NLS

USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-charmaps=${CHARMAPSDIR}
NO_ARCH=	yes

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

M17N_DISTFILE=	${DISTNAME}${EXTRACT_SUFX}
GLIBC_VERSION=	2.3.6
GLIBC_DISTFILE=	glibc-${GLIBC_VERSION}.tar.bz2
CHARMAPSDIR=	glibc-${GLIBC_VERSION}/localedata/charmaps

M17N_DATADIR=	${PREFIX}/share/m17n

post-extract:
	cd ${WRKSRC}; ${TAR} xjf ${DISTDIR}/${GLIBC_DISTFILE} ${CHARMAPSDIR}

post-patch:
	@${REINPLACE_CMD} -E 's|(m17n_scriptdir = ).*|\1${PREFIX}/bin|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
