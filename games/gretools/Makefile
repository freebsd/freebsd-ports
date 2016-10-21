# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gretools
PORTVERSION=	1.2.4
PORTREVISION=	13
CATEGORIES=	games gnome
MASTER_SITES=	http://randomwalker.info/gretools/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME vocabulary builder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pathfix pkgconfig python shebangfix
SHEBANG_FILES=	${WRKSRC}/gretools.py
USE_GNOME=	gnomeprefix pygnome2
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python -t|/usr/bin/env python|g ; \
		 s|@prefix@|${LOCALBASE}|g ; s|@share@|share|g' \
		 ${WRKSRC}/gretools.in
	@${REINPLACE_CMD} -e 's|gtk\.TRUE|True|g ; \
		 s|gtk\.FALSE|False|g ; \
		 s|gtk\.idle_add|gobject\.idle_add|g' ${WRKSRC}/gretools.py

post-install:
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gretools/gretools.pyc
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gretools/gretools.pyo
	${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR}/gretools \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gretools
	${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR}/gretools \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gretools

.include <bsd.port.mk>
