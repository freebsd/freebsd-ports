# New ports collection makefile for:	nethack-qt
# Date created:		So   6 Apr 1997 04:25:57 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	nethack
PKGNAMESUFFIX=	-qt
PORTVERSION=	3.3.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh${PORTVERSION:S/.//g}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_QT_VER=	2
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" MOC="${MOC}" LIBQT="-l${QTNAME}" \
		QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}"
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

pre-everything::
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "!! You cannot install nethack and nethack-qt in parallel  !!"
	@${ECHO} "!! But nethack-qt might read your prior nethack scores    !!"
	@${ECHO} "!! Don't forget to backup your nethack libdir if it's     !!"
	@${ECHO} "!! important for you                                      !!"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/include/config.h

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
