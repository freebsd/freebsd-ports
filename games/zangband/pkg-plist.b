@exec mkdir %D/%%ANGBANDLIB%%/data
@exec chown -R games:games %D/%%ANGBANDLIB%%/apex %D/%%ANGBANDLIB%%/data
@exec chmod 775 %D/%%ANGBANDLIB%%
@exec chmod -R ug+rw,o-rw %D/%%ANGBANDLIB%%/*
@exec chmod -R o+r %D/%%ANGBANDLIB%%/help %D/%%ANGBANDLIB%%/xtra
@exec chmod 1777 %D/%%ANGBANDLIB%%/save %D/%%ANGBANDLIB%%/user
@dirrm %%ANGBANDLIB%%/apex
@dirrm %%ANGBANDLIB%%/bone
@dirrm %%ANGBANDLIB%%/data
@dirrm %%ANGBANDLIB%%/edit
@dirrm %%ANGBANDLIB%%/file
@dirrm %%ANGBANDLIB%%/help
@dirrm %%ANGBANDLIB%%/info
@dirrm %%ANGBANDLIB%%/pref
@dirrm %%ANGBANDLIB%%/save
@dirrm %%ANGBANDLIB%%/script
@dirrm %%ANGBANDLIB%%/user
@dirrm %%ANGBANDLIB%%/xtra/font
@dirrm %%ANGBANDLIB%%/xtra/graf
@dirrm %%ANGBANDLIB%%/xtra/music
@dirrm %%ANGBANDLIB%%/xtra/sound
@dirrm %%ANGBANDLIB%%/xtra
@dirrm %%ANGBANDLIB%%
