# Ports collection makefile for:  boost-docs
# Date Created:			  20 March 2009
# Whom:				  Alexander Churanov <churanov.port.maintainer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	boost-docs
COMMENT=	Documentation for libraries from boost.org

USE_BZIP2=	yes

DOCSDIR=	${PREFIX}/share/doc/boost
UNIQ=		/usr/bin/uniq

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/boost-all/common.mk"
.include "${PORTSDIR}/devel/boost-all/sites.mk"

do-install:
# Documentation & examples
	${MKDIR} ${DOCSDIR}

	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 0444 {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	${FIND} ${WRKSRC} -name ".cvsignore" -delete
	cd ${WRKSRC} &&\
	${FIND} . -name "*.htm" -o -name "*.html"  -o -name "*.css"\
		-o -name "*.jp*g" -o -name "*.png" -o -name "*.gif"\
		| ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -

	cd ${WRKSRC}/libs &&\
	${FIND} . -name "example" -o -name "examples" -o -name "*example*.cpp"\
		-o -name "*example*.c" -o -name "*example*.hpp" | ${UNIQ} |\
		${GREP} -v "assign/test" | ${GREP} -v "iterator/test" | \
		${GREP} -v "range/test" |\
	${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR}/libs -

.include <bsd.port.post.mk>
