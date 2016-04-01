# Created by: ijliao
# $FreeBSD$

PORTNAME=	wrapper
PORTVERSION=	2.4
CATEGORIES=	lang
MASTER_SITES=	SF/rexx${PORTNAME}/rexx${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RexxWrapper-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that wraps Rexx source or tokenised code into an executable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rexx:lang/rexx-regina
RUN_DEPENDS=	rexx:lang/rexx-regina

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rexx=regina
DATADIR=	${PREFIX}/share/rexx${PORTNAME}

post-patch:	.SILENT
	@${REINPLACE_CMD} -Ee "/^compiler\.unix/s,'.*','${CC:T}'," \
		-e "s,cc\.cc = .*,cc.${CC:T} = '${CC}'," \
		-e "/ opt/s/-[Og][^' ]?//" \
		-e "s,cflags\. = '(.*)',cflags. = '\1 ${CFLAGS}'," \
		${WRKSRC}/rexxwrap.cmd
	@${REINPLACE_CMD} 's/-compiler=$$(CC/&:T/' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rexxwrapper

.include <bsd.port.mk>
