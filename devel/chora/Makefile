# Ports collection makefile for:  Chora
# Date created:			  Mon Nov 26, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	chora
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel www

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	The Horde CVS web-viewer

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_SVN		: if you don't need subversion;
#
# - WITHOUT_CVSPS	: if you don't need cvsps;
#
# - WITHOUT_CVSGRAPH	: if you don't need cvsgraph;
#
# - A4 or DJ		: if you run enscript with this paper size.
#
#-----------------------------------------------------------------------

.if !defined(WITHOUT_SVN)
RUN_DEPENDS+=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion
.endif

.if !defined(WITHOUT_CVSPS)
RUN_DEPENDS+=	${LOCALBASE}/bin/cvsps:${PORTSDIR}/devel/cvsps-devel
.endif

.if !defined(WITHOUT_CVSGRAPH)
RUN_DEPENDS+=	${LOCALBASE}/bin/cvsgraph:${PORTSDIR}/devel/cvsgraph
.endif

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

USE_HORDE=	base pkg-message
USE_GETTEXT=	yes
PORTDOCS=	README BUGS CHANGES CREDITS INSTALL RELEASE_NOTES TODO

pre-configure:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"		\
		-e "s|/usr/bin/cvsgraph|${LOCALBASE}/bin/cvsgraph|"	\
		-e "s|/usr/bin/svn|${LOCALBASE}/bin/svn|"		\
		${WRKSRC}/config/conf.xml
	@${REINPLACE_CMD} -e "s|%%CVSROOT%%|${CVSROOT}|"		\
		-e "s|%%CONFDIR%%|${CONFDIR}|"				\
		${WRKSRC}/config/sourceroots.php.dist

pre-install:
.if !defined(WITHOUT_CVSPS)
	@if ! ${PKG_INFO} -I -x cvsps-devel > /dev/null ; then \
	  ${ECHO_MSG} "Error: cvsps-devel is required, not cvsps." ; \
	  ${FALSE} ; \
	fi
.endif

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
