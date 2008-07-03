# New ports collection makefile for: 	codelite
# Date created:				7 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	codelite
DISTVERSION=	${REL_VERSION}.r${SVN_REVISION}
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF
DISTNAME=	CodeLite-rev${SVN_REVISION}-v${REL_VERSION}.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl

OPTIONS=	CSCOPE	"Enable CScope integration" OFF

WRKSRC=	${WRKDIR}/CodeLite-Rev${SVN_REVISION}-V${REL_VERSION}

USE_ZIP=	yes
USE_WX=	2.8
WX_UNICODE=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes

REL_VERSION=	1.0
SVN_REVISION=	1789

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

post-patch:
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g' \
	    ${WRKSRC}/configure ${WRKSRC}/makefile.base
	${REINPLACE_CMD} -e 's|$${cur_rev}|${SVN_REVISION}|' \
		${WRKSRC}/le_makerevision.sh
	# CTags already installed
	(if [ -f ${LOCALBASE}/include/readtags.h ]; then \
	    ${RM} ${WRKSRC}/CodeLite/readtags.h; \
	 fi; \
	)
.if ${ARCH} == "amd64"
	${REINPLACE_CMD} -e 's|-Wall|-fPIC -Wall|g' \
		${WRKSRC}/configure ${WRKSRC}/makefile.base
.endif

do-configure:
	(cd ${WRKSRC} && ${SH} ${CONFIGURE_SCRIPT})

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/config
	${MKDIR} ${DATADIR}/rc
	${MKDIR} ${DATADIR}/templates
	${MKDIR} ${DATADIR}/lexers
	${MKDIR} ${DATADIR}/debuggers
	${MKDIR} ${DATADIR}/plugins
	${MKDIR} ${DATADIR}/images
	${MKDIR} ${PREFIX}/include/UnitTest++
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
	${INSTALL_DATA} ${WRKSRC}/Runtime/sdk/lib/unix/libUnitTest++.a ${PREFIX}/lib
	(cd ${WRKSRC}/Runtime/sdk/include/UnitTest++ &&  ${COPYTREE_SHARE} \* ${PREFIX}/include/UnitTest++)
.for lib in CodeFormatter Subversion cscope Gizmos
	${INSTALL_DATA} ${WRKSRC}/lib/${lib}.so ${DATADIR}/plugins
.endfor
	${INSTALL_DATA} ${WRKSRC}/Runtime/index.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Runtime/astyle.sample ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Runtime/svnreport.html ${DATADIR}
	(cd ${WRKSRC}/Runtime/images && ${COPYTREE_SHARE} \*.png ${DATADIR}/images)
	${INSTALL} -d ${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/Runtime/codelite.desktop ${PREFIX}/share/applications/

.include <bsd.port.post.mk>
