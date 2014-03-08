# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	flick
PORTVERSION=	2.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	ftp://flux.cs.utah.edu/flux/flick/2.1/
MASTER_SITES=	http://www.sourcefiles.org/Programming/Compilers/Other/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible IDL Compiler Kit

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I-||' ${WRKSRC}/GNUmakeconf.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/guts && ${INSTALL_DATA} *.ps ${DOCSDIR})
	(cd ${WRKSRC}/doc/usersguide && ${INSTALL_DATA} *.ps ${DOCSDIR})
.endif

.include <bsd.port.mk>
