# Created by: leo
# $FreeBSD$

PORTNAME=	Shout
PORTVERSION=	2.1
CATEGORIES=	audio perl5
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl glue for libshout MP3 streaming source library

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2

PERL_CONFIGURE=	yes

MAN3=		Shout.3

DOCSDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	${REINPLACE_CMD} -i '' -e 's/CCFLAGS/INC/' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -i -pe '$$_ .= " ${PTHREAD_LIBS}" if /^LDDLFLAGS/;' ${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example*.pl ${DOCSDIR}
.endif

.include <bsd.port.mk>
