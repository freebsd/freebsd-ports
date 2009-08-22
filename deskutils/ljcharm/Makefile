# Ports collection Makefile for:	ljcharm
# Date created:				2003-02-26
# Whom:					schmidtcarl@earthlink.net
#
# $FreeBSD$
#

PORTNAME=	charm
PORTVERSION=	1.9.1
CATEGORIES=	deskutils net
MASTER_SITES=	SF/lj${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	seawolf@marinewolf.net
COMMENT=	A menu-driven python-based livejournal client

MAN1=charm.1
MAN5=charmrc.5

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	1.9.1

post-patch:
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's,share/doc/charm,${DOCSDIR},'  ${WRKSRC}/setup.py
.else
	${REINPLACE_CMD} -e '/data_files = /d' \
			-e '/man\/man1/s,^[ ]*,      data_files = [ ,' \
			${WRKSRC}/setup.py
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/CHANGES.charm ${DOCSDIR}/CHANGES
	${INSTALL_DATA} ${WRKSRC}/README.charm ${DOCSDIR}/README
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.charmrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
