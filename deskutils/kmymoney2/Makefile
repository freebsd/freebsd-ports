# New ports collection makefile for:   kmymoney
# Date created:        16 September 2001
# Whom:                dwcjr
#
# $FreeBSD$
#

PORTNAME=	kmymoney2
PORTVERSION=	0.4
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kmymoney2

MAINTAINER=	dmitry_makovey@mail.com

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes

# After path

USE_AUTOCONF_VER=213
USE_AUTOMAKE_VER=14

CONFIGURE_ARGS+=	--with-qt-dir=${X11BASE} --with-qt-moc=${X11BASE}/bin \
			--prefix=${PREFIX}
MAKE_ENV+=		MOC=${X11BASE}/bin/moc2
MAKE_ENV+=		LIBQT="-lqt2"

MAKE_ENV+=		PATH=${WRKDIR}/bin:${PATH}
CONFIGURE_ENV+=		PATH=${WRKDIR}/bin:${PATH}

pre-configure:
	${MKDIR} ${WRKDIR}/bin
	-${LN} -sf ${PREFIX}/bin/aclocal14 ${WRKDIR}/bin/aclocal
	-${LN} -sf ${PREFIX}/bin/autoconf213  ${WRKDIR}/bin/autoconf
	-${LN} -sf ${PREFIX}/bin/autoheader213  ${WRKDIR}/bin/autoheader
	-${LN} -sf ${PREFIX}/bin/automake14  ${WRKDIR}/bin/automake

post-configure:
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION} && ${GMAKE} -f Makefile.dist ${CONFIGURE_ENV}

post-install:
	cd ${PREFIX}/bin && ${LN} -fs i386-portbld-freebsd4.5-kmymoney2 kmymoney2

#USE_AUTOCONF=	yes
#MAKE_ENV= AUTOMAKE=automake14 ACLOCAL=aclocal14 AUTOCONF=autoconf213

.include <bsd.port.mk>
