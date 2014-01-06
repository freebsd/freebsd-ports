# $FreeBSD$

SYMFONY2_PORTVERSION=	2.3.4
MASTER_SITES?=	http://pear.symfony.com/get/

BUILD_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.symfony.com.reg:${PORTSDIR}/devel/pear-channel-symfony2

RUN_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.symfony.com.reg:${PORTSDIR}/devel/pear-channel-symfony2

PKGNAMEPREFIX?=	pear-

DIST_SUBDIR=	Symfony2
PEAR_CHANNEL=	symfony2
PEAR_AUTOINSTALL=	yes

symfony2-Symfony_Bridge_DoctrineBridge-DEPEND=	pear-Symfony_Bridge_DoctrineBridge>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Bridge_DoctrineBridge
symfony2-Symfony_Bridge_MonologBridge-DEPEND=	pear-Symfony_Bridge_MonologBridge>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Bridge_MonologBridge
symfony2-Symfony_Bridge_TwigBridge-DEPEND=	pear-Symfony_Bridge_TwigBridge>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Bridge_TwigBridge
symfony2-Symfony_Component_BrowserKit-DEPEND=	pear-Symfony_Component_BrowserKit>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_BrowserKit
symfony2-Symfony_Component_ClassLoader-DEPEND=	pear-Symfony_Component_ClassLoader>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_ClassLoader
symfony2-Symfony_Component_Config-DEPEND=	pear-Symfony_Component_Config>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Config
symfony2-Symfony_Component_Console-DEPEND=	pear-Symfony_Component_Console>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Console
symfony2-Symfony_Component_CssSelector-DEPEND=	pear-Symfony_Component_CssSelector>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_CssSelector
symfony2-Symfony_Component_DependencyInjection-DEPEND=	pear-Symfony_Component_DependencyInjection>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_DependencyInjection
symfony2-Symfony_Component_DomCrawler-DEPEND=	pear-Symfony_Component_DomCrawler>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_DomCrawler
symfony2-Symfony_Component_EventDispatcher-DEPEND=	pear-Symfony_Component_EventDispatcher>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_EventDispatcher
symfony2-Symfony_Component_Filesystem-DEPEND=	pear-Symfony_Component_Filesystem>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Filesystem
symfony2-Symfony_Component_Finder-DEPEND=	pear-Symfony_Component_Finder>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Finder
symfony2-Symfony_Component_Form-DEPEND=	pear-Symfony_Component_Form>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Form
symfony2-Symfony_Component_HttpFoundation-DEPEND=	pear-Symfony_Component_HttpFoundation>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_HttpFoundation
symfony2-Symfony_Component_HttpKernel-DEPEND=	pear-Symfony_Component_HttpKernel>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_HttpKernel
symfony2-Symfony_Component_Intl-DEPEND=	pear-Symfony_Component_Intl>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Intl
symfony2-Symfony_Component_Locale-DEPEND=	pear-Symfony_Component_Locale>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Locale
symfony2-Symfony_Component_OptionsResolver-DEPEND=	pear-Symfony_Component_OptionsResolver>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_OptionsResolver
symfony2-Symfony_Component_Process-DEPEND=	pear-Symfony_Component_Process>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Process
symfony2-Symfony_Component_PropertyAccess-DEPEND=	pear-Symfony_Component_PropertyAccess>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_PropertyAccess
symfony2-Symfony_Component_Routing-DEPEND=	pear-Symfony_Component_Routing>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Routing
symfony2-Symfony_Component_Security-DEPEND=	pear-Symfony_Component_Security>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Security
symfony2-Symfony_Component_Serializer-DEPEND=	pear-Symfony_Component_Serializer>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Serializer
symfony2-Symfony_Component_Stopwatch-DEPEND=	pear-Symfony_Component_Stopwatch>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Stopwatch
symfony2-Symfony_Component_Templating-DEPEND=	pear-Symfony_Component_Templating>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Templating
symfony2-Symfony_Component_Translation-DEPEND=	pear-Symfony_Component_Translation>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Translation
symfony2-Symfony_Component_Validator-DEPEND=	pear-Symfony_Component_Validator>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/devel/pear-Symfony_Component_Validator
symfony2-Symfony_Component_Yaml-DEPEND=	pear-Symfony_Component_Yaml>=${SYMFONY2_PORTVERSION}:${PORTSDIR}/textproc/pear-Symfony_Component_Yaml

.if defined(USE_SYMFONY2_RUN)
. for DEP in ${USE_SYMFONY2_RUN}
.  if !defined(symfony2-${DEP}-DEPEND)
UNKNOWN_SYMFONY2_PACKAGES+=	${DEP}
.  else
RUN_DEPENDS+=	${symfony2-${DEP}-DEPEND}
.  endif
. endfor
.endif

.if defined(USE_SYMFONY2_BUILD)
. for DEP in ${USE_SYMFONY2_BUILD}
.  if !defined(symfony2-${DEP}-DEPEND)
UNKNOWN_SYMFONY2_PACKAGES+=	${DEP}
.  else
BUILD_DEPENDS+=	${symfony2-${DEP}-DEPEND}
.  endif
. endfor
.endif

.if defined(UNKNOWN_SYMFONY2_PACKAGES)
IGNORE=	unknown Symfony2 package(s): ${UNKNOWN_SYMFONY2_PACKAGES}
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

