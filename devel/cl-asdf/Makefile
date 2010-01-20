# New ports collection Makefile for:	cl-asdf
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

# The source tarball was obtained from the project's GIT repository:
# wget -O asdf-1.374.tar.gz "http://common-lisp.net/gitweb?p=projects/asdf/asdf.git;a=snapshot;h=f6dfe94d2836534a7be050127123cc16fee87c48;sf=tgz"

PORTNAME=	asdf
PORTVERSION=	1.374
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A system definition facility for Common Lisp

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES+=	pkg-message

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${MKDIR} ${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
	@${SED}	-i '' -e 's|%%PREFIX%%|${PREFIX}|' ${ASDF_PATHNAME}/asdf.lisp
	@${SED}	-e 's|%%ASDF_PATHNAME%%|${ASDF_PATHNAME}/asdf|' \
		-e 's|%%ASDF_REGISTRY%%|${ASDF_REGISTRY}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/asdf-init.lisp > \
		${PREFIX}/etc/asdf-init.lisp.default
	@[ -f ${PREFIX}/etc/asdf-init.lisp ] || \
		${CP} ${PREFIX}/etc/asdf-init.lisp.default \
		${PREFIX}/etc/asdf-init.lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.cl-asdf.mk>
.include <bsd.port.mk>
