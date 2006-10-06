# New ports collection makefile for:	codeblocks
# Date created:				November, 15th 2005
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=		codeblocks
PORTVERSION=		1.0r2
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-1.0rc2
EXTRACT_SUFX=		.tgz

MAINTAINER=	m.sund@arcor.de
COMMENT=	Open source, cross-platform, free C/C++ IDE

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	wx_gtk2u_xrc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
USE_LDCONFIG=	yes

TARGETS=	tinyXML scintilla sdk wxDockit src console_runner doc
PLUGINS=	Astyle CompilerGCC DebuggerGDB CodeCompletion ClassWizard DefMimeHandler PluginsWizard ToDo XPManifest
EXTENSIONS=	CC CPP LD LIB

GCC=	${CC}
CPP=	${CXX}
LD=	${CXX}
LIB=	ar

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Code::Blocks is currently not supported for FreeBSD versions prior to FreeBSD 5
.endif
.if ${ARCH} == ia64 && ${OSVERSION} >= 600000 && ${OSVERSION} < 700000
BROKEN=		Code::Blocks is currently not supported on IA64 FreeBSD 6
.endif

post-extract:
	@${FIND} -E ${WRKSRC} -type f -iregex \
	".*\.(c|h|cpp|am|in|doxy|cbp|template|xrc|html)" -print0 | \
	${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@for f in `${FIND} -E ${WRKSRC} -type f -name Makefile -print`; \
	do ${CP} $$f $$f.bak && (${CAT} $$f.bak | ${TR} -d "\r" > $$f); done
	@${FIND} -E ${WRKSRC} -type f -iregex ".*\.txt" -print0 | \
	${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@(${CAT} ${WRKSRC}/update | ${TR} -d "\r" > ${WRKSRC}/update.sh)

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.for t in ${TARGETS}
. for e in ${EXTENSIONS}
	@${ECHO_CMD} "${t}_${e}=${${e}}" >> ${WRKSRC}/gcc.defs
. endfor
.endfor
.for p in ${PLUGINS}
. for e in ${EXTENSIONS}
	@${ECHO_CMD} "plugin_${p}_${e}=${${e}}" >> ${WRKSRC}/gcc.defs
. endfor
.endfor

post-build:
	@(${FIND} -E ${WRKSRC} -type f -iregex ".*\.(orig|bak)" -exec ${RM} {} \;)
	@${CHMOD} +x ${WRKSRC}/update.sh
	@(cd ${WRKSRC} && ./update.sh)
	@${MV} ${WRKSRC}/output/share/CodeBlocks ${WRKSRC}/output/share/codeblocks
	@${MV} ${WRKSRC}/output/console_runner.exe ${WRKSRC}/output/console_runner
	@${MV} ${WRKSRC}/output/codeblocks.exe ${WRKSRC}/output/codeblocks

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/output/console_runner ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/output/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/output/*.so ${PREFIX}/lib
	@(cd ${WRKSRC}/output && ${FIND} share -type d -exec ${MKDIR} ${PREFIX}/{} \;)
	@(cd ${WRKSRC}/output && ${FIND} share -name "*.so" -type f -exec ${INSTALL_PROGRAM} {} ${PREFIX}/{} \;)
	@(cd ${WRKSRC}/output && ${FIND} share  \! -name "*.so" -type f -exec ${CP} {} ${PREFIX}/{} \;)

post-install:
	@${ECHO_CMD} bin/${PORTNAME} >> ${TMPPLIST}
	@${ECHO_CMD} bin/console_runner >> ${TMPPLIST}
	@${ECHO_CMD} lib/libcodeblocks.so >> ${TMPPLIST}
	@${ECHO_CMD} lib/libwxscintilla.so >> ${TMPPLIST}
	@(cd ${WRKSRC}/output && ${FIND} share -type f -exec ${ECHO_CMD} {} >> ${TMPPLIST} \;)
	@${ECHO_CMD} @dirrm share/${PORTNAME}/images/codecompletion >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm share/${PORTNAME}/images >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm share/${PORTNAME}/lexers >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm share/${PORTNAME}/plugins >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm share/${PORTNAME}/templates >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm share/${PORTNAME} >> ${TMPPLIST}

.include <bsd.port.post.mk>
