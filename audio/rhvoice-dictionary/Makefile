PORTNAME=	RHVoice-dictionary
DISTVERSION=	g20190109
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Russian dictionary for RHVoice to improve the tone of speech

RUN_DEPENDS=	RHVoice>0:audio/rhvoice

USE_GITHUB=	yes
GH_ACCOUNT=	vantu5z
GH_TAGNAME=	45ddf91

NO_BUILD=	yes
NO_ARCH=	yes

ETCDIR=		${PREFIX}/etc/RHVoice

FILES=		phrase_dict.txt locations_dict.txt names_dict.txt person_names_dict.txt abbr_dict.txt yo_dict.txt
ETC_SUBDIR=	dicts/Russian
PLIST_FILES=	${FILES:S|^|${ETCDIR}/${ETC_SUBDIR}/|}

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/${ETC_SUBDIR}
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${ETCDIR}/${ETC_SUBDIR}
.endfor

.include <bsd.port.mk>
