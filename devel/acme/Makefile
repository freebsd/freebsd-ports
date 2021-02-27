# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	acme
DISTVERSION=	0.97.${SVN_REV}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Crossassembler for 6502, 65c02 and 65816 processors

LICENSE=	GPLv2

USES=		dos2unix tar:xz
DOS2UNIX_GLOB=	*.txt

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}"

BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS EXAMPLES

SVN_REPO=	https://svn.code.sf.net/p/acme-crossass/code-0/trunk
SVN_REV=	r319

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/acme ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ACME_Lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/ultraedit_wordfile/ReadMe.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/me
	${INSTALL_DATA} ${WRKSRC}/examples/*.a ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/me/*.a ${STAGEDIR}${EXAMPLESDIR}/me/

cklatest:
	@${ECHO_CMD} "Current revision: ${SVN_REV}"
	@${ECHO_CMD} -n "SVN revision: r"
	@svn info ${SVN_REPO} 2>&1 \
		| ${SED} -n 's|^Revision:\ \([0-9]*\)|\1|p'

dist: clean
	@svn export ${SVN_REPO} ${WRKSRC}
	@${TAR} -C ${WRKDIR} -cvJpf ${DISTDIR}/${DISTFILES} ${DISTNAME}

.include <bsd.port.mk>
