# New ports collection makefile for:    scmxx
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	scmxx
PORTVERSION=	0.6.3.5
CATEGORIES=	comms
MASTER_SITES=	http://ma2geo.mathematik.uni-karlsruhe.de/~hendrik/scmxx/download/ \
		http://ma2geo.mathematik.uni-karlsruhe.de/~hendrik/scmxx/download/old/

MAINTAINER=	janos.mohacsi@bsd.hu

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

MAN1=		scmxx.1

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for file in phonebook sms.txt vCalendar.vcs vCard.vcf
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
