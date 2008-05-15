# New ports collection makefile for: 	codelite
# Date created:				7 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	codelite
DISTVERSION=	r1528
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gahr

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

OPTIONS=	CSCOPE	"Enable CScope integration" OFF

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_WX=	2.8
WX_UNICODE=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

post-patch:
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g' \
	    ${WRKSRC}/configure ${WRKSRC}/makefile.base

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/config
	${MKDIR} ${DATADIR}/rc
	${MKDIR} ${DATADIR}/templates
	${MKDIR} ${DATADIR}/lexers
	${MKDIR} ${DATADIR}/debuggers
	${MKDIR} ${DATADIR}/plugins
	${MKDIR} ${DATADIR}/images
	${INSTALL_PROGRAM} ${WRKSRC}/Runtime/CodeLiteUR ${PREFIX}/bin/CodeLite
	${INSTALL_SCRIPT} ${WRKSRC}/Runtime/le_dos2unix.sh ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/Runtime/le_exec.sh ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/Runtime/le_killproc.sh ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/sdk/ctags/ctags-le ${PREFIX}/bin
	(cd ${WRKSRC}/Runtime/config/ && ${COPYTREE_SHARE} \* ${DATADIR}/config)
	(cd ${WRKSRC}/Runtime/rc/ && ${COPYTREE_SHARE} \*.xrc ${DATADIR}/rc)
	(cd ${WRKSRC}/Runtime/templates && ${COPYTREE_SHARE} \* ${DATADIR}/templates)
	(cd ${WRKSRC}/Runtime/lexers && ${COPYTREE_SHARE} \* ${DATADIR}/lexers)
	${INSTALL_DATA} ${WRKSRC}/lib/Debugger.so ${DATADIR}/debuggers
.for lib in CodeFormatter Subversion ReferenceAnalyser cscope Gizmos
	${INSTALL_DATA} ${WRKSRC}/lib/${lib}.so ${DATADIR}/plugins
.endfor
	${INSTALL_DATA} ${WRKSRC}/Runtime/index.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Runtime/astyle.sample ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Runtime/svnreport.html ${DATADIR}
	(cd ${WRKSRC}/Runtime/images && ${COPYTREE_SHARE} \*.png ${DATADIR}/images)
	${INSTALL} -d ${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/Runtime/codelite.desktop ${PREFIX}/share/applications/

.include <bsd.port.post.mk>
