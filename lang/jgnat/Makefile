# New ports collection makefile for:	jgnat
# Date created:         8 Apr 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	jgnat
PORTVERSION=	1.1.p
PORTREVISION=	2
CATEGORIES=	lang java
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cdrom.com/pub/languages/ada/compiler/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://wuarchive.wustl.edu/languages/ada/compiler/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cs.kuleuven.ac.be/pub/Ada-Belgium/mirrors/cs.nyu.edu/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cs.tu-berlin.de/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/mirror/cs.nyu.edu/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.lip6.fr/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cnam.fr/pub/Ada/PAL/compiler/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.fsz.bme.hu/pub/ada/gnat/jgnat/jgnat-1.1p/split-1.1p/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([^\.]+)$/\1/}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	coop9211@uidaho.edu

BUILD_DEPENDS=	${LOCALBASE}/bin/adagcc:${PORTSDIR}/lang/gnat

USE_GMAKE=	yes
USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/${DISTNAME:C@-([^\-]+)$@/\1@}

.include <bsd.port.pre.mk>

LIBDIR=		${PREFIX}/lib/jgnat
ADAINCDIR=	${LIBDIR}/adainclude
ADALIBDIR=	${LIBDIR}/adalib
JARDIR=		${PREFIX}/share/java/classes
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}

do-install:
.for dir in ${LIBDIR} ${ADAINCDIR} ${ADALIBDIR} ${JARDIR}
	@${MKDIR} ${dir}
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/../bin/* ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/../lib/jgnat.jar ${JARDIR}
	@${INSTALL_DATA} ${WRKSRC}/../lib/jgnat/adainclude/* ${ADAINCDIR}
	@${INSTALL_DATA} ${WRKSRC}/../lib/jgnat/adalib/* ${ADALIBDIR}
	@${CHMOD} a-r ${ADALIBDIR}/*.ali

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
