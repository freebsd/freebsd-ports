# Created by: Roland Smith <rsmith@xs4all.nl>
# $FreeBSD$

PORTNAME=		stl
PORTVERSION=		3.1
CATEGORIES=		graphics python
MASTER_SITES=		http://rsmith.home.xs4all.nl/software/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		py-${PORTNAME}-${PORTVERSION}

MAINTAINER=		rsmith@xs4all.nl
COMMENT=		Converts STL models to POV-Ray meshes or PostScript/PDF images

LICENSE=		BSD

# bypass infrastructure bug
OPTIONSFILE=		${PORT_DBDIR}/py-${PORTNAME}/options

USES=		zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	YES
PYDISTUTILS_EGGINFO=	py_stl-${PORTVERSION}-py${PYTHON_VER}.egg-info

CONFLICTS=		stl2pov-[0-9]*

MAN1=			stl2ps.1 stlinfo.1 stl2pov.1

OPTIONS_DEFINE=		PYCAIRO
PYCAIRO_DESC=		Use (py)Cairo to enable stl2pdf

NO_STAGE=	yes
.include <bsd.port.options.mk>

STL_SCRIPTS=		stl2pov stl2ps stlinfo

.if ${PORT_OPTIONS:MPYCAIRO}
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}cairo>1.8:${PORTSDIR}/graphics/py-cairo
MAN1+=			stl2pdf.1
PLIST_SUB=		STL2PDF=""
STL_SCRIPTS+=		stl2pdf
.else
PLIST_SUB=		STL2PDF="@comment "
.endif

NO_BUILD=		YES

post-install:
.if empty(PORT_OPTIONS:MPYCAIRO)
	@${RM} -f ${PREFIX}/bin/stl2pdf.py
.endif
.for s in ${STL_SCRIPTS}
	${INSTALL_MAN} ${WRKSRC}/${s}.1 ${MANPREFIX}/man/man1
	@${MV} ${PREFIX}/bin/${s}.py  ${PREFIX}/bin/${s}
.endfor

.include <bsd.port.mk>
