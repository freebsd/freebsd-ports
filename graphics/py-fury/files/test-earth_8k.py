# from https://fury.gl/latest/auto_examples/01_introductory/viz_texture.html#sphx-glr-auto-examples-01-introductory-viz-texture-py

from fury import actor, io, window
from fury.data import fetch_viz_textures, read_viz_textures

scene = window.Scene()


fetch_viz_textures()
filename = read_viz_textures('1_earth_8k.jpg')
image = io.load_image(filename)

scene.add(actor.texture_on_sphere(image))

interactive = True
if interactive:
    window.show(scene, size=(600, 600), reset_camera=False)
window.record(scene, size=(900, 768), out_path='viz_texture.png')
