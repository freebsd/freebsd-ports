# New ports collection makefile for:	lyx
# Date created:		27 April 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.0.3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flathill
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-jp-kit0.10b4for${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.ORG
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

#RUN_DEPENDS=	platex:${PORTSDIR}/japanese/platex-euc
#.if defined(WITH_ISPELL)
#RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
#.endif
LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

BROKEN=		Incomplete pkg-plist

USE_XPM=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
STRIP=
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"
MAN1=		lyx.1 reLyX.1

pre-fetch:
.if !defined(WITH_ISPELL)
	@${ECHO_MSG} "if you want this port build with spell checker type"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

post-patch:
	@cd ${WRKSRC}; ${PATCH} -p1 < ../lyx-jp-patch

post-install:
	@strip ${PREFIX}/bin/lyx
	${INSTALL_DATA} ${WRKDIR}/ChangeLog.jis ${PREFIX}/share/lyx
	${INSTALL_DATA} ${WRKDIR}/README.jis ${PREFIX}/share/lyx
	${INSTALL_DATA} ${WRKSRC}/lib/lyxrc.jp ${PREFIX}/share/lyx

.include <bsd.port.mk>
