PORTNAME=	leo_center
PORTVERSION=	0.4.70
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LeoFS Web console
WWW=		https://leo-project.net/

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	leo-project
GH_TAGNAME=	${PORTVERSION:C/0$//}

DIST_SUBDIR=	leofs

RUN_DEPENDS=	rubygem-haml>=0:www/rubygem-haml \
		rubygem-leo_manager_client>=0.4.13:databases/rubygem-leo_manager_client \
		rubygem-sinatra-contrib1>=0:www/rubygem-sinatra-contrib1 \
		rubygem-sinatra1>=1.4.3:www/rubygem-sinatra1 \
		rubygem-thin>=0:www/rubygem-thin

USE_RC_SUBR=	${PORTNAME}

LEOFS_USER=	leofs
LEOFS_GROUP=	leofs
USERS=		${LEOFS_USER}
GROUPS=		${LEOFS_GROUP}

ETCDIR=		${PREFIX}/etc/leofs

LEOFS_LOGDIR=	/var/log/leofs
LEOFS_RUNDIR=	/var/run/leofs

PLIST_SUB+=	LEOFS_USER=${LEOFS_USER} \
		LEOFS_GROUP=${LEOFS_GROUP} \
		LEOFS_LOGDIR=${LEOFS_LOGDIR} \
		LEOFS_RUNDIR=${LEOFS_RUNDIR}

SUB_LIST+=	LEOFS_USER=${LEOFS_USER} \
		LEOFS_GROUP=${LEOFS_GROUP} \
		LEOFS_LOGDIR=${LEOFS_LOGDIR} \
		LEOFS_RUNDIR=${LEOFS_RUNDIR}

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} \
		's|config_file = .*|config_file = "${ETCDIR}/${PORTNAME}.conf"|' \
		${WRKSRC}/lib/helpers.rb
	@${REINPLACE_CMD} \
		's|#{settings.root}/log/|${LEOFS_LOGDIR}/${PORTNAME}_|' \
		${WRKSRC}/app.rb

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${LEOFS_LOGDIR} ${STAGEDIR}${LEOFS_RUNDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		'! -regex .*/log$$ ! -regex .*/log/.*$$ ! -regex .*/.git.*$$ ! -regex .*\.bak ! -regex .*\.orig')
	${INSTALL_DATA} ${WRKSRC}/config.yml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
