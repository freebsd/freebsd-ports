# New ports collection makefile for:	gxditview (part of ja-groff)
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	1.17.2
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTNAME=	groff-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	okazaki/groff
PATCHFILES=	${DISTNAME}-jgroff-0.0.2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff

# declare USE_AUTOCONF_VER as 213 until bsd.port.mk supports 252 (or later)
USE_AUTOCONF_VER=	213
.if ${USE_AUTOCONF_VER} == 213
USE_REINPLACE=	yes
.endif
USE_GMAKE=	yes
USE_IMAKE=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-nippon
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"

MAKE_ENV=	GROFF_PREFIX=${LOCALBASE} NIPPONDEFINES="-DNIPPON"
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src/xditview
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/src/xditview

MAN1=		gxditview.1

.include <bsd.port.pre.mk>

# workaround for autoconf-2.13

CONFIGUREIN_FILTER=	\
		-e 's|AC_INIT|dnl|g;' \
		-e 's|AC_CONFIG_SRCDIR|AC_INIT|g;' \
		-e 's|AC_OUTPUT|dnl|g;' \
		-e 's|AC_CONFIG_FILES|AC_OUTPUT|g;'

ACLOCAL_FILTER=	\
	-e 's/AC_LANG_POP[(]C[+][+][)]/AC_LANG_RESTORE/g;' \
	-e 's/AC_LANG_PUSH[(]C[+][+][)]/AC_LANG_SAVE[]AC_LANG_CPLUSPLUS/g;'

post-extract:
	${CP} ${FILESDIR}/Imakefile ${WRKSRC}

post-patch:
.if ${USE_AUTOCONF_VER} == 213
	${CP} -p ${WRKSRC}/configure.ac ${WRKSRC}/configure.in
	${REINPLACE_CMD} ${CONFIGUREIN_FILTER} ${WRKSRC}/configure.in
	${REINPLACE_CMD} ${ACLOCAL_FILTER} ${WRKSRC}/aclocal.m4
.endif

.include <bsd.port.post.mk>
