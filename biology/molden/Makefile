# New ports collection makefile for:	molden
# Version required:	3.4
# Date created:		1998-11-14
# Whom:			rmiya
#
# $FreeBSD$
#

DISTNAME=	molden3.4
PKGNAME=	molden-3.4
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.caos.kun.nl/pub/molgraph/molden/
MASTER_SITES+=	ftp://ftp.caos.kun.nl/pub/molgraph/molden/bin/
DISTFILES=	molden3.4.tar.Z molden3.4-freebsd

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

EXTRACT_ONLY=	molden3.4.tar.Z
RESTRICTED=     "free for academic, non profit usage; do not re-distribute source and executable"

.if ${MACHINE_ARCH} == "alpha"
DONOTUSE_ORIGINALBINARY=	yes
.endif

pre-build:
.if defined(DONOTUSE_ORIGINALBINARY)
	(cd ${WRKSRC}; ${CP} makefile Makefile)
	(cd ${WRKSRC}; ./change_parameter)
	@echo "********************"
	@echo "**  re-build with customizations"
	@echo "**  maxorb: 256 -> 1024"
	@echo "**  maxatm: 150 -> 300"
	@echo "********************"
.else
	@echo "********************"
	@echo "**  using original binary"
	@echo "********************"
.endif

do-build:
.if defined(DONOTUSE_ORIGINALBINARY)
	(cd ${WRKSRC};${MAKE})
.else
	${CP} ${DISTDIR}/${DISTNAME}-freebsd ${WRKSRC}/molden
.endif

pre-install:
	${RM} -rf ${PREFIX}/share/doc/molden
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/molden
	${MKDIR} ${PREFIX}/share/doc/molden/doc
	${MKDIR} ${PREFIX}/share/doc/molden/test
.endif

do-install:
	strip  ${WRKSRC}/molden
	${INSTALL_PROGRAM} ${WRKSRC}/molden ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/molden/doc
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/doc/molden/test
.endif

.include <bsd.port.mk>
