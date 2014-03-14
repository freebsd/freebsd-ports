# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	scmxx
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Data exchange utility for Siemens mobile phones

USES=		gettext iconv gmake tar:bzip2
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		scmxx.1
MANLANG=	"" ru de it
DOCS=		README docs/*.txt
EXAMPLES=	sms.txt vCalendar.vcs vCard.vcf

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} \
		${REINPLACE_CMD} -e "s|CFLAGS=|CFLAGS+=|g"

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
