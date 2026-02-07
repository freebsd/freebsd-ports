PORTNAME=	sccs
CATEGORIES=	devel

COMMENT=	Source Code Control System (SCCS)
WWW=		https://sccs.sourceforge.net/

TEST_DEPENDS=	star:archivers/star

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	patch \
		sccs
TESTCOMPONENTS=	${COMPONENTS:Npatch}

# These files are installed by the patch target,
# but they belong to sysutils/schilyutils.
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/opatch
	${RM} ${STAGEDIR}${PREFIX}/bin/spatch
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/opatch.1
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/patch.1
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/spatch.1

# This test suite installs a temp copy of the schilytools to /tmp.
# The directories are hard-coded unfortunately.
pre-test:
	@${ECHO_MSG} '=> cleaning old test files'
	${RM} -r /tmp/sccstests /tmp/SCCSTEST
	@${ECHO_MSG} '=> running test suite'

.include "${MASTERDIR}/Makefile.master"
