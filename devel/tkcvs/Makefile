# New ports collection makefile for:	tkcvs
# Date created:         02 Aug 1996
# Whom:                 shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkcvs
PORTVERSION=	8.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	andrew.nau.ua@gmail.com
COMMENT=	Tcl/Tk frontends to CVS, Subversion and diff

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

USE_REINPLACE=	yes
NO_BUILD=	yes

MAN1=		tkcvs.1

WISH=		wish8.4
TCLSH=		tclsh8.4

post-patch:
	@${GREP} -lR "exec wish " ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|exec wish |exec ${WISH} |g'

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${TCLSH} doinstall.tcl -nox ${PREFIX}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ vendor5readme.pdf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
