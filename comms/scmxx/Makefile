# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	scmxx
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Data exchange utility for Siemens mobile phones

USES=		gettext iconv gmake tar:bzip2
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		README docs/*.txt
EXAMPLES=	sms.txt vCalendar.vcs vCard.vcf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_libiconv=no
.endif

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} \
		${REINPLACE_CMD} -e "s|CFLAGS=|CFLAGS+=|g"

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
