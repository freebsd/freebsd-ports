# New ports collection makefile for:	pymol
# Date created:			July 18, 2002
# Whom:				Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$

PORTNAME=	pymol
PORTVERSION=	0.82
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pymol
DISTNAME=	pymol-${PORTVERSION:S/./_/}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PMW:${PORTSDIR}/x11-toolkits/pmw
LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/Mesa3

WRKSRC=         ${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes
USE_REINPLACE=  yes
USE_PYTHON=	yes

pre-patch:
	@${INSTALL_DATA} ${WRKSRC}/setup/Rules.linux ${WRKSRC}/Rules.make

post-patch:
	@${INSTALL_DATA} ${WRKSRC}/setup/pymol.com.linux-rh7x ${WRKSRC}/setup/pymol.com
	@${REINPLACE_CMD} 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/setup/pymol.com
	@${REINPLACE_CMD} 's,@PYTHON_VERSION@,${PYTHON_VERSION},g' ${WRKSRC}/Rules.make

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/setup/pymol.com ${PREFIX}/bin/pymol
	@${MKDIR} ${PREFIX}/share/pymol
	@${TAR} -C ${WRKSRC} -chf - modules test | \
		${TAR} -xf - -C ${PREFIX}/share/pymol
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/pymol/modules
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/pymol/modules

.include <bsd.port.mk>
