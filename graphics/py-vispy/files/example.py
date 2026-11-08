import numpy as np
from vispy import app, scene

# 1. Generate beautiful, swirling 3D point data (a torus knot)
num_points = 10000
t = np.linspace(0, 4 * np.pi, num_points)
x = np.sin(t) * (2 + np.cos(3 * t))
y = np.cos(t) * (2 + np.cos(3 * t))
z = np.sin(3 * t)
points = np.vstack((x, y, z)).T

# 2. Map coordinates to RGB colors to create a vivid visual gradient
colors = np.zeros((num_points, 4))
colors[:, 0] = (x - x.min()) / (x.max() - x.min())  # Red channel
colors[:, 1] = (y - y.min()) / (y.max() - y.min())  # Green channel
colors[:, 2] = (z - z.min()) / (z.max() - z.min())  # Blue channel
colors[:, 3] = 1.0  # Alpha (opacity)

# 3. Create the window Canvas with a dark theme background
canvas = scene.SceneCanvas(
    title="Beautiful 3D VisPy Point Cloud",
    keys="interactive",
    show=True,
    bgcolor="#111116",
    size=(800, 600)
)

# 4. Set up a 3D view and attach an Arcball camera for fluid rotation
view = canvas.central_widget.add_view()
view.camera = "arcball"
view.camera.fov = 45
view.camera.distance = 8

# 5. Add the high-performance Point Visual to the scene
scatter = scene.visuals.Markers()
scatter.set_data(
    pos=points,
    edge_color=None,
    face_color=colors,
    size=4  # Removed 'scaling=True'
)
view.add(scatter)

# 6. Create an animation timer to gently spin the visualization automatically
def on_timer(event):
    view.camera.azimuth += 0.5
    canvas.update()

timer = app.Timer(interval=1/60, connect=on_timer, start=True)

# 7. Execute the native application event loop
if __name__ == "__main__":
    app.run()

