# New ports collection makefile for:	qtez
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	qtez
PORTVERSION=	0.93.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://qtez.ibl.sk/qtez/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@freebsd.org
COMMENT=	Qt Rapid Application Development Environment for X Window System

USE_PERL5=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_LIBTOOL=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" QTEZ="${DATADIR}" MSG2QM="${MOC}"
MAKE_ENV=	QTEZ="${DATADIR}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
	@${PERL} -pi -e 's|-O2 |\$$CXXFLAGS |g ; \
		 s|include/qaction.h|include/${QTNAME}/qaction.h|g ; \
		 s|qtdir/include$$|qtdir/include/${QTNAME}|g ; \
		 s|-lqt|-l${QTNAME}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|doc po images|doc images|g ; \
		 s|prefix\)/qtez/plugins|prefix\)/lib/qtez/plugins|g ; \
		 s|prefix\)/qtez/img|QTEZ\)/img|g'

pre-configure:
	@cd ${WRKSRC} && ${PERL} automoc
	@cd ${WRKSRC}/src && ${SH} ./autolinks.sh

post-install:
	@${SED} -e "s:/usr/X11R6:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
