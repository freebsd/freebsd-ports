# New ports collection makefile for:    boa-constructor
# Date created:         		15 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	boaconstructor
PORTVERSION=	0.0.5
CATEGORIES=	devel python
MASTER_SITES=	http://ftp1.sourceforge.net/${MASTER_SITE_SUBDIR}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	boa-constructor
DISTNAME=	Boa-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/wxc.so:${PORTSDIR}/x11-toolkits/py-wxPython

WRKSRC=		${WRKDIR}/Boa-${PORTVERSION}

USE_ZIP=	yes
USE_PYTHON=	yes

do-configure:
	@${PERL} -pi -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|' \
		${WRKSRC}/Explorer.gtk.cfg

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/Boa
	@(cd ${WRKSRC} && ${TAR} --exclude .cvsignore --exclude "*.orig" -c -f - .) \
		| (cd ${PREFIX}/share/Boa && ${TAR} --unlink -x -f -)
	@printf "#!/bin/sh\n${PYTHON_CMD} ${PREFIX}/share/Boa/Boa.py\n" \
		> ${WRKDIR}/Boa.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/Boa.sh ${PREFIX}/bin/Boa

.include <bsd.port.mk>
