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

USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_IMAKE=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-nippon
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"

MAKE_ENV=	GROFF_PREFIX=${LOCALBASE} NIPPONDEFINES="-DNIPPON"
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src/xditview
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/src/xditview

MAN1=		gxditview.1

# workaround for autoconf-2.13

CONFIGUREIN_FILTER=	\
		-e 's|AC_INIT|dnl|g;' \
		-e 's|AC_CONFIG_SRCDIR|AC_INIT|g;' \
		-e 's|AC_OUTPUT|dnl|g;' \
		-e 's|AC_CONFIG_FILES|AC_OUTPUT|g;'

ACLOCAL_FILTER=	-e 's/AC_LANG_POP\(C\+\+\)/AC_LANG_RESTORE/g;' \
		-e 's/AC_LANG_PUSH\(C\+\+\)/AC_LANG_SAVE\nAC_LANG_CPLUSPLUS/g;'

post-extract:
	${LN} -sf configure.ac ${WRKSRC}/configure.in
	${CP} ${FILESDIR}/Imakefile ${WRKSRC}

post-patch:
	${PERL} -pi ${CONFIGUREIN_FILTER} ${WRKSRC}/configure.in
	${PERL} -pi ${ACLOCAL_FILTER} ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
